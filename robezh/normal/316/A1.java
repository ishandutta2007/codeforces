import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static boolean isLetter(char c) {
        return c >= 'A' && c <= 'Z';
    }

    public static boolean isNumber(char c) {
        return c >= '0' && c <= '9';
    }

    public static void main(String args[]) {
        Set<Character> set = new HashSet<>();
        int cntQ = 0;
        Scanner scanner = new Scanner(System.in);

        String string = scanner.nextLine();
        for (int i = 0; i < string.length(); i++) {
            if (isLetter(string.charAt(i)))
                set.add(string.charAt(i));
            if (string.charAt(i) == '?')
                cntQ++;
        }
        if (set.size() >= 10) {
            System.out.println("0");
            return;
        }
        BigInteger bigInteger = BigInteger.ONE;
        for (int i = 0; i < set.size(); i++)
            bigInteger = bigInteger.multiply(new BigDecimal(10 - i).toBigInteger());
        for (int i = 0; i < cntQ; i++)
            bigInteger = bigInteger.multiply(BigInteger.TEN);
        if (isLetter(string.charAt(0)) || string.charAt(0) == '?') {
            bigInteger = bigInteger.divide(BigInteger.TEN);
            bigInteger = bigInteger.multiply(new BigDecimal(9).toBigInteger());
        }
        System.out.println(bigInteger);


    }
}