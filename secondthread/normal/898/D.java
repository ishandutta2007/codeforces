import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int lengthOfRange=fs.nextInt();
		int maxClocksInRange=fs.nextInt()-1;
		int[] countingSort=new int[1000002];
		for (int i=0; i<n; i++) {
			countingSort[fs.nextInt()]++;
		}
		
		int total=0;
		for (int i=0; i<lengthOfRange; i++) {
			total+=countingSort[i];
		}
		
		int i=lengthOfRange-1;
		int count=0;
		while (total>maxClocksInRange) {
			if (countingSort[i]!=0) {
				total--;
				count++;
				countingSort[i]--;
			}
			else {
				i--;
			}
		}
		
		i=lengthOfRange;
		while (i<countingSort.length) {
			total-=countingSort[i-lengthOfRange];
			total+=countingSort[i];
			int diff=total-maxClocksInRange;
			if (diff>0) {
				total-=diff;
				count+=diff;
				countingSort[i]-=diff;
			}
			i++;
		}
		System.out.println(count);
	}
	
	public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
        public FastScanner() {
            try    {
                br = new BufferedReader(new InputStreamReader(System.in));
//              br = new BufferedReader(new FileReader("testdata.out"));
                st = new StringTokenizer("");
            } catch (Exception e){e.printStackTrace();}
        }
        public String next() {
                if (st.hasMoreTokens())    return st.nextToken();
            try {st = new StringTokenizer(br.readLine());}
                catch (Exception e) {e.printStackTrace();}
            return st.nextToken();
        }
        public int nextInt() {return Integer.parseInt(next());}
        public long nextLong() {return Long.parseLong(next());}
        public double nextDouble() {return Double.parseDouble(next());}

        public String nextLine() {
                String line = "";
            try {line = br.readLine();}
            catch (Exception e) {e.printStackTrace();}
                return line;
        }
	}
}