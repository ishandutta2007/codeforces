import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		/*
		try {
			inputStream = new FileInputStream("a.in");
			outputStream = new FileOutputStream("a.out");
		} catch (FileNotFoundException e){
			System.err.println("File not found");
			return;
		}
		*/
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		solver.solve(in, out);
		out.close();
	}
}

class Solver {
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		Friend[] f = new Friend[n];
		for (int i = 0; i < n; ++i)
			f[i] = new Friend();
		for (int i = 0; i < n; ++i) {
			int phoneNumber = in.nextInt();
			f[i].name = in.next();
			String[] phone = new String[phoneNumber];
			for (int j = 0; j < phoneNumber; ++j)
				phone[j] = in.next();
			f[i].setPhone(phone);
			f[i].setNumbers();
		}
		int max = 0;
		Vector<String> ans = new Vector<String>();

		for (int i = 0; i < n; ++i)
			max = Math.max(max, f[i].taxiNumber);

		for (int i = 0; i < n; ++i)
			if (f[i].taxiNumber == max)
				ans.add(f[i].name);

		out.print("If you want to call a taxi, you should call: ");
		String s = ans.toString();
		s = s.replace("[", "");
		s = s.replace("]", "");
		out.print(s);
		out.println(".");
		
		ans.clear();
		max = 0;

		for (int i = 0; i < n; ++i)
			max = Math.max(max, f[i].pizzaNumber);

		for (int i = 0; i < n; ++i)
			if (f[i].pizzaNumber == max)
				ans.add(f[i].name);

		out.print("If you want to order a pizza, you should call: ");
		s = ans.toString();
		s = s.replace("[", "");
		s = s.replace("]", "");
		out.print(s);
		out.println(".");
		ans.clear();
		max = 0;

		for (int i = 0; i < n; ++i)
			max = Math.max(max, f[i].girlNumber);

		for (int i = 0; i < n; ++i)
			if (f[i].girlNumber == max)
				ans.add(f[i].name);

		out.print("If you want to go to a cafe with a wonderful girl, you should call: ");
		s = ans.toString();
		s = s.replace("[", "");
		s = s.replace("]", "");
		out.print(s);
		out.println(".");

	}
}

class Friend {
	public String name;
	public int pizzaNumber, taxiNumber, girlNumber;
	public String[] phone;

	public void setPhone(String[] a) {
		phone = a;
		for (int i = 0; i < phone.length; ++i)
			phone[i] = phone[i].replace("-", "");
	}
	public void setNumbers() {
		for (int i = 0; i < phone.length; ++i) {
			boolean ind = true;
			for (int j = 1; j < phone[i].length(); ++j)
				if (phone[i].charAt(j) >= phone[i].charAt(j - 1))
					ind = false;
			if (ind)
				pizzaNumber++;
			ind = true;
			for (int j = 1; j < phone[i].length(); ++j)
				if (phone[i].charAt(j) != phone[i].charAt(j - 1))
					ind = false;
			if (ind)
				taxiNumber++;
		}
		girlNumber = phone.length - pizzaNumber - taxiNumber;
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
        	reader = new BufferedReader(new InputStreamReader(stream));
        	tokenizer = null;
    	}

    	public String next() {
        	while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            		try {
                		tokenizer = new StringTokenizer(reader.readLine());
            		} catch (IOException e) {
                		throw new RuntimeException(e);
            		}
        	}
        	return tokenizer.nextToken();
    	}

    	public long nextLong() {
        	return Long.parseLong(next());
    	}
	
	public int nextInt() {
        	return Integer.parseInt(next());
    	}

	public double nextDouble() {
        	return Double.parseDouble(next());
    	}
}