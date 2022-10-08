import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*


e = expected, a = actual

e_1 - a_1 
a_2 - e_2
e_3 - a_3


================

-a_1 +a_2 -a_3 => maximize
+e_1 -e_2 +e_3 => constant

Each person is either + per question or - per question
sort the question by their net score
questionValue*timesCounted

2^10 * 1024 * log


1
4 4
6 2 0 10
1001
0010
0110
0101

I say  4 3 1 2
answer 2 3 4 1

Expect: 6 2 0 10
Me: Get 6 1 4 5
Him:    3 4 7 4
 */
public class E {

	static boolean[][] personGotQuestion;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int nPeople=fs.nextInt();
			int nQuestions=fs.nextInt();
			int[] expectedScores=fs.readArray(nPeople);
			personGotQuestion=new boolean[nPeople][nQuestions];
			for (int person=0; person<nPeople; person++) {
				char[] line=fs.next().toCharArray();
				for (int q=0; q<nQuestions; q++)
					personGotQuestion[person][q]=line[q]=='1';
			}
			
			ArrayList<Integer>[] count=new ArrayList[1<<nPeople];
			for (int q=0; q<nQuestions; q++) {
				int mask=0;
				for (int p=0; p<nPeople; p++)
					mask+=(1<<p)*(personGotQuestion[p][q]?1:0);
				if (count[mask]==null) count[mask]=new ArrayList<>();
				count[mask].add(q);
			}
			int nNonzero=0;
			for (ArrayList<Integer> l:count) if (l!=null) nNonzero++;
			Question[] questions=new Question[nNonzero];
			nNonzero=0;
			for (int mask=0; mask<1<<nPeople; mask++) {
				if (count[mask]==null) continue;
				questions[nNonzero++]=new Question(mask, count[mask]);
			}
			long best=0; int bestMask=0;
			for (int mask=0; mask<1<<nPeople; mask++) {
				//if this is a 1 bit, expected is positive
				long constantToAdd=0;
				for (int i=0; i<nPeople; i++) if ((mask&(1<<i))!=0) constantToAdd+=expectedScores[i]; else constantToAdd-=expectedScores[i];
				
				long bestOtherDist=bestOtherDist(mask, nQuestions, nPeople, questions, false);
				if (bestOtherDist+constantToAdd>best) {
					best=bestOtherDist+constantToAdd;
					bestMask=mask;
				}
				
//				System.out.println("For mask "+mask+" "+constantToAdd+" "+bestOtherDist);
			}
//			out.println(best+" "+bestMask);
			finalAns=new int[nQuestions];
			bestOtherDist(bestMask, nQuestions, nPeople, questions, true);
			for (int i=0; i<nQuestions; i++) {
				out.print(finalAns[i]+" ");
			}
			out.println();
		}
		out.close();
	}

	static int[] finalAns;
	
	static long bestOtherDist(int mask, int nQuestions, int nPeople, 
			Question[] questions, boolean markAns) {
		for (Question q:questions) {
			q.netValue=0;
			for (int i=0; i<nPeople; i++) {
				if ((q.mask&(1<<i))!=0) {
					if ((mask&(1<<i))!=0) {
						q.netValue--;
					}
					else {
						q.netValue++;
					}
				}
			}
		}
		Arrays.sort(questions);
		long ans=0;
		int next=1;
		for (Question qq:questions) {
//			for (int i=0; i<qq.count; i++) {
//				ans+=next*qq.netValue;
//				next++;
//			}
			for (int i:qq.originalPositions) {
				ans+=next*qq.netValue;
				if (markAns) finalAns[i]=next;
				next++;
			}
		}
		return ans;
	}
	
	static class Question implements Comparable<Question> {
		int mask;
		int netValue;
		int count;
		ArrayList<Integer> originalPositions;
		
		public Question(int mask, ArrayList<Integer> originalPositions) {
			this.mask=mask;
			this.count=originalPositions.size();
			this.originalPositions=originalPositions;
		}
		
		public int compareTo(Question o) {
			return Integer.compare(netValue, o.netValue);
		}
	}
	
	static final Random random=new Random();
	static final int mod=1_000_000_007;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}