import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class D {
	
	static HashMap<Integer, Integer> compress=new HashMap<>();
	static HashMap<Integer, Integer> decompress=new HashMap<>();
	
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		compress(a);
		
		Entry[] entries=new Entry[n];
		for (int i=0; i<n; i++) entries[i]=new Entry(a[i], i);
		Arrays.sort(entries);
		
		DisjointSet dj=new DisjointSet(n+1);
		int bestCutoff=0;
		int numberOfParts=0;
		for (Entry e:entries) {
			dj.join(e.indexOf, e.indexOf+1);
			if (dj.numPartSizes==1) {
				int partCount=dj.partSize[dj.existingSizes.first()];
				if (partCount>numberOfParts) {
					numberOfParts=dj.partSize[dj.existingSizes.first()];
					bestCutoff=e.value;
				}
			}
		}
		System.out.println(decompress.get(bestCutoff)+1);
		
	}
	
	static void compress(int[] a) {
		ArrayList<Integer> sorted=new ArrayList<>();
		for (int i:a)
			sorted.add(i);
		Collections.sort(sorted);
		for (int i=0; i<sorted.size(); i++) {
			compress.put(sorted.get(i), i);
			decompress.put(i, sorted.get(i));
		}
		
		for (int i=0; i<a.length; i++)
			a[i]=compress.get(a[i]);
	}
	
	static class Entry implements Comparable<Entry> {
		int value, indexOf;
		public Entry(int value, int indexOf) {
			this.value=value;
			this.indexOf=indexOf;
		}
		
		public int compareTo(Entry o) {
			return value-o.value;
		}
	}
	
	
	private static class Pair {
        int value;
        int height;
        int size=1;
        public Pair(int value, int height) {
            this.value=value;
            this.height=height;
        }
    }
    
    private static class DisjointSet {
        Pair[] pairs;
        int[] partSize;
        int numPartSizes=0;
        TreeSet<Integer> existingSizes=new TreeSet<>();
        public DisjointSet(int n) {
            pairs=new Pair[n];
            partSize=new int[n+1];
            
            for (int i=0; i<n; i++)
                pairs[i]=new Pair(i, 0);
        }
        
        public int find(int index) {
        	if (pairs[index].value==index)
        		return index;
        	return pairs[index].value=find(pairs[index].value);
        }
        
        public void join(int a, int b) {
            a=find(a);
            b=find(b);
            if (a==b)
                return;
            
            if (pairs[a].height<pairs[b].height) {
                pairs[a].value=b;
                adjustPartSize(pairs[b].size, pairs[a].size);
                pairs[b].size+=pairs[a].size;
            }
            else {
                pairs[b].value=a;
                adjustPartSize(pairs[b].size, pairs[a].size);
                pairs[a].size+=pairs[b].size;
                if (pairs[a].height==pairs[b].height) {
                    pairs[a].height++;//if they are equal, a just got one taller
                }
            }
        }
        
        private void adjustPartSize(int oldSize1, int oldSize2) {
        	int newSize=oldSize1+oldSize2;
        	if (oldSize1!=1) {
        		partSize[oldSize1]--;
        		if (partSize[oldSize1]==0) {
        			existingSizes.remove(oldSize1);
        			numPartSizes--;
        		}
        	}
        	if (oldSize2!=1) {
        		partSize[oldSize2]--;
        		if (partSize[oldSize2]==0) {
        			existingSizes.remove(oldSize2);
        			numPartSizes--;
        		}
        	}
        	if (partSize[newSize]==0) {
        		numPartSizes++;
        		existingSizes.add(newSize);
        	}
        	partSize[newSize]++;
        }
    }

	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
			
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
	}

	
}