import java.util.ArrayList;
import java.util.Scanner;

public class VK {
//I couldn't register for this competition because I was like a minute late. I finished the first problem in like 3 minutes, and haven't seen
	//the rest, so I am doing virtual participation now...
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String line=s.nextLine();
		ArrayList<String> sections=new ArrayList<>();
		sections.add(line);
		for (int index=0; index<sections.size(); index++) {
			if (sections.get(index).contains("VK")) {
				String toRemove=sections.get(index);
				sections.remove(index);
				sections.add(toRemove.substring(0, toRemove.indexOf("VK")));
				sections.add(toRemove.substring(toRemove.indexOf("VK")+2));
				index--;
			}
		}
		
		boolean bonus=false;
		for (String st:sections) {
			if (st.length()>=3) {
				bonus=true;
			}
			if (st.length()==2&&(st.startsWith("V")||st.endsWith("K"))) {
				bonus=true;
			}
		}
		
		System.out.println((bonus?1:0)+sections.size()-1);
	}

}