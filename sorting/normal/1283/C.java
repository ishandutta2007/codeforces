import java.util.*;
import java.io.DataInputStream; 
import java.io.FileInputStream; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.StringTokenizer; 
 
public class FriendsAndGifts{
 
    static class Reader 
	{ 
		final private int BUFFER_SIZE = 1 << 16; 
		private DataInputStream din; 
		private byte[] buffer; 
		private int bufferPointer, bytesRead; 
 
		public Reader() 
		{ 
			din = new DataInputStream(System.in); 
			buffer = new byte[BUFFER_SIZE]; 
			bufferPointer = bytesRead = 0; 
		} 
 
		public Reader(String file_name) throws IOException 
		{ 
			din = new DataInputStream(new FileInputStream(file_name)); 
			buffer = new byte[BUFFER_SIZE]; 
			bufferPointer = bytesRead = 0; 
		} 
 
		public String readLine() throws IOException 
		{ 
			byte[] buf = new byte[64]; // line length 
			int cnt = 0, c; 
			while ((c = read()) != -1) 
			{ 
				if (c == '\n') 
					break; 
				buf[cnt++] = (byte) c; 
			} 
			return new String(buf, 0, cnt); 
		} 
 
		public int nextInt() throws IOException 
		{ 
			int ret = 0; 
			byte c = read(); 
			while (c <= ' ') 
				c = read(); 
			boolean neg = (c == '-'); 
			if (neg) 
				c = read(); 
			do
			{ 
				ret = ret * 10 + c - '0'; 
			} while ((c = read()) >= '0' && c <= '9'); 
 
			if (neg) 
				return -ret; 
			return ret; 
		} 
 
		public long nextLong() throws IOException 
		{ 
			long ret = 0; 
			byte c = read(); 
			while (c <= ' ') 
				c = read(); 
			boolean neg = (c == '-'); 
			if (neg) 
				c = read(); 
			do { 
				ret = ret * 10 + c - '0'; 
			} 
			while ((c = read()) >= '0' && c <= '9'); 
			if (neg) 
				return -ret; 
			return ret; 
		} 
 
		public double nextDouble() throws IOException 
		{ 
			double ret = 0, div = 1; 
			byte c = read(); 
			while (c <= ' ') 
				c = read(); 
			boolean neg = (c == '-'); 
			if (neg) 
				c = read(); 
 
			do { 
				ret = ret * 10 + c - '0'; 
			} 
			while ((c = read()) >= '0' && c <= '9'); 
 
			if (c == '.') 
			{ 
				while ((c = read()) >= '0' && c <= '9') 
				{ 
					ret += (c - '0') / (div *= 10); 
				} 
			} 
 
			if (neg) 
				return -ret; 
			return ret; 
		} 
 
		private void fillBuffer() throws IOException 
		{ 
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
			if (bytesRead == -1) 
				buffer[0] = -1; 
		} 
 
		private byte read() throws IOException 
		{ 
			if (bufferPointer == bytesRead) 
				fillBuffer(); 
			return buffer[bufferPointer++]; 
		} 
 
		public void close() throws IOException 
		{ 
			if (din == null) 
				return; 
			din.close(); 
		} 
	} 
 
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] arr = new int[n+1];
        for(int i = 1;i<arr.length;i++){
            arr[i] = s.nextInt();
        }
 
        boolean[] ba = new boolean[n+1];
        Arrays.fill(ba, false);
        for(int i = 1;i<arr.length;i++){
            ba[arr[i]] = true;
        }
        ArrayList<Integer> list = new ArrayList<>();
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for(int i = 1;i<ba.length;i++){
            if(ba[i] == false){
                list.add(i);
                map.put(i, -1);
            }
        }
        int j = 0;
        for(int i = 1;i<arr.length;i++){
            if(arr[i] == 0){
                if(i == list.get(j)){
                    if(j == 0){
                        arr[i] = list.get(j+1);
                        map.put(list.get(j+1), i);
                        Collections.swap(list, j, j+1);
                        j++;
                    }else{
                        for(int key : map.keySet()){
                            if(map.get(key) != -1){
                                arr[i] = key;
                                arr[map.get(key)] = list.get(j);
                                map.put(list.get(j), map.get(key));
                                map.put(key, i);
                                j++;
                                break;
                            }
                        }
                    }
                }else{
                    arr[i] = list.get(j);
                    map.put(list.get(j), i);
                    j++;
                }
            }
        }
        for(int i = 1;i<arr.length;i++){
            System.out.print(arr[i] + " ");
        }
    }
}