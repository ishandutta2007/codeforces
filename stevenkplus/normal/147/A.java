import java.util.Scanner;


public class A147
{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String line = in.nextLine();
        line = line.replaceAll( "\\s+"," " );
        String punc = "[.,!?]";
        System.out.println(line.replaceAll("\\s*("+punc+")\\s*","$1 "));
    }
}