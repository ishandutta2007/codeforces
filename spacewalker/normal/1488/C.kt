import kotlin.math.*;
import java.util.Scanner;

fun getCost(asep : Int, a : Int, b : Int, k : Int) : Int {
    var bsep = k - asep;
    return max(a + asep + min(a, asep), b + bsep + min(b, bsep));
}

fun solve(n : Int, _x : Int, _y : Int) : Int {
    var x = _x;
    var y = _y;
    if (x > y) {
        var temp = x;
        x = y;
        y = temp;
    }
	var a = x - 1; var b = n - y; var k = max(x, y) - min(x, y) - 1;
    var lo = 0; var hi = k;
    // println("$lo $hi");
    while (hi - lo > 1) {
        var mid = (lo + hi) / 2;
        /*
        println(mid);
        println(getCost(mid, a, b, k));
        println(getCost(mid+1, a, b, k));
        */
        if (getCost(mid, a, b, k) > getCost(mid+1, a, b, k)) {
            lo = mid;
        } else {
            hi = mid;
		}
    }
    if (lo == hi) return getCost(lo, a, b, k);
    else return min(getCost(lo, a, b, k), getCost(lo + 1, a, b, k));
}

fun main() {
    val reader = Scanner(System.`in`)
    var t = reader.nextInt();
    for (tc in 0 until t) {
        var n = reader.nextInt();
        var x = reader.nextInt();
        var y = reader.nextInt();
        println(solve(n, x, y));
    }
}