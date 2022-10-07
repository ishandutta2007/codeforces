import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;


public class A081 {
	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String b = r.readLine();
		LinkedList<Character> st = new LinkedList<Character>();
		for(char c:b.toString().toCharArray()) {
			Character d =st.peek();
			if(d!=null&&d.charValue()==c) st.pop();
			else
				st.push(c);
		}
		StringBuffer bf = new StringBuffer();
		for(Character c:st) 
			bf.append(c);
		System.out.println(bf.reverse().toString());
	}
}