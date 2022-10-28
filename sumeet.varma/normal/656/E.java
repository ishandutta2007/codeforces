import java.util.*;

public class AprilFools16QD {

	static Scanner sc;
	static int N;
	static int a[][];
	static int ans = 0;
	
	public static void main(String[] args) throws Exception{
		sc = new Scanner(System.in);
		
		N = sc.nextInt();
		a = new int[N][N];
		
		inp(0);
		inp3(0);
		inp6(0);
		
		System.out.println(ans);
	}
	
	static boolean inp(int i){
		inp2(i , 0);
		return i == N - 1 ? true : inp(++i);
	}
	
	static boolean inp2(int i, int j){
		a[i][j] = sc.nextInt();
		return j == N - 1 ? true : inp2(i , ++j);
	}
	
	static boolean inp3(int k){
		inp4(k , 0);
		return k == N - 1 ? true : inp3(++k);
	}
	
	static boolean inp4(int k, int i){
		inp5(k , i , 0);
		return i == N - 1 ? true : inp4(k, ++i);
	}
	
	static boolean inp5(int k, int i, int j){
		a[i][j] = Math.min(a[i][j], a[i][k] + a[k][j]);
		return j == N - 1 ? true : inp5(k , i , ++j);
	}

	static boolean inp6(int i){
		inp7(i , 0);
		return i == N - 1 ? true : inp6(++i);
	}
	
	static boolean inp7(int i, int j){
		ans = Math.max(ans, a[i][j]);
		return j == N - 1 ? true : inp7(i , ++j);
	}
}