import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static ArrayList<BigInteger> fac;
    static int[] cnt = new int[50];
    static BigInteger get(int n) {
        BigInteger res = BigInteger.ONE;
//        for(Integer xint :arrayList) System.out.println(xint);
        int sum = cnt[0];
        for(int i = 1, idx = 0; i < 50 && idx < n; i++, idx++) {
            sum += cnt[i];
            res = res.multiply(BigInteger.valueOf(sum - idx));
        }
        for(int i = 0; i < 50; i++) {
            res = res.divide(fac.get(cnt[i]));
        }
        return res;
    }

    static BigInteger solve(long x) {
        ArrayList<Integer> arrayList = new ArrayList<Integer>();
        for(int i = 0; i < 50; i++) cnt[i] = 0;
        for(int i = 2; i < 50; i++) {
            arrayList.add((int)(x % i));
            cnt[(int)(x % i)]++;
            x /= i;
            if(x == 0) break;
        }
//        System.out.println(arrayList);
        BigInteger a = get(arrayList.size());
        if(cnt[0] != 0) {
            cnt[0]--;
            BigInteger b = get(arrayList.size() - 1);
//            System.out.println(b);
            a = a.subtract(b);
        }
        return a;
    }

    public static void main(String[] args) {
        fac = new ArrayList<BigInteger>();
        fac.add(BigInteger.ONE);
        for(int i = 1; i < 50; i++) {
            fac.add(fac.get(fac.size() - 1).multiply(BigInteger.valueOf(i)));
        }
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        while(T-- > 0) {
            long x = scanner.nextLong();
            System.out.println(solve(x).subtract(BigInteger.ONE));
        }
    }
}