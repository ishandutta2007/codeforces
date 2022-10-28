import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Stack;

public class R5qCLongestRegularBracketSequence {
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    Stack<Integer> stack = new Stack<Integer>();
	    
	    int lastun = -1;
	    int max = 0,count = 1;
	    
	    char s[] = br.readLine().toCharArray();
	    int n = s.length; 

	    for(int i=0;i<n;i++){
	    	if(s[i] == '(')
	    		stack.push(i);
	    	else{
	    		if(stack.isEmpty())
	    			lastun = i;
	    		else
	    			stack.pop();
	    	}
	    	int dis = stack.isEmpty() ? i - lastun : i - Math.max(lastun, stack.peek());
	    	if(dis > max){
	    		max = dis;
	    		count = 1;
	    	}
	    	else if(dis == max)
	    		count++;
	    }
	    
	    if(max == 0)	count = 1;
	    w.println(max + " " + count);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}