import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Set;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int divide=fs.nextInt();
		int k=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++)
			a[i]=fs.nextInt();
		
		HashMap<Integer, Integer> low=new HashMap<>();
		HashMap<Integer, Integer> high=new HashMap<>();
		for (int i:a) {
			int lowKey=(i-1)/divide;
			int highKey=i/divide;
			if (low.containsKey(lowKey))
				low.put(lowKey, low.get(lowKey)+1);
			else
				low.put(lowKey, 1);
			
			if (high.containsKey(highKey))
				high.put(highKey, high.get(highKey)+1);
			else
				high.put(highKey, 1);
		}
		long total=0;
		if (k==0) {
			ArrayList<Integer> list=new ArrayList<Integer>();
			for (int i:a)
				list.add(i);
			Collections.sort(list);
			for (int i=0; i<n; i++)
				a[i]=list.get(i);
			
			int lastDivisor=-1;
			int divisorCount=0;
			int lastNumCount=0;
			int lastNum=-1;
			for (int i:a) {
				if (i%divide==0) {
					total+=lastNumCount*(long)lastNumCount;
					total+=divisorCount*lastNumCount;
					lastNumCount=0;
					divisorCount=0;
					continue;
				}
				if (i==lastNum) {
					lastNumCount++;
					continue;
				}
				else {
//					System.out.println("i= "+i+", but lastNum= "+lastNum);
					total+=lastNumCount*(long)lastNumCount;
					total+=divisorCount*lastNumCount;
					divisorCount+=lastNumCount;
					lastNumCount=1;
//					System.out.println("total now: "+total);
				}
				int newDivisor=i/divide;
				if (newDivisor!=lastDivisor) {
//					System.out.println("i "+i+", new divisor "+newDivisor+" from "+lastDivisor);
					lastDivisor=newDivisor;
					divisorCount=0;
					lastNum=i;
					continue;
				}
				else {
//					divisorCount++;
					lastNum=i;
				}
//				System.out.println(i+" "+total);
			}
//			System.out.println("total: "+total+" lastNumCount: "+lastNumCount+" divisor count: "+divisorCount);
			total+=lastNumCount*(long)lastNumCount;
			total+=divisorCount*lastNumCount;
			System.out.println(total);
			return;
		}
		
		Set<Integer> lowKeys=low.keySet();
		for (int i:lowKeys) {
			int lowCount=low.get(i);
			if (!high.containsKey(i+k))
				continue;
			int highCount=high.get(i+k);
			total+=lowCount*(long)highCount;
		}
		System.out.println(total);
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