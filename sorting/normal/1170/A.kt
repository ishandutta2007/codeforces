import kotlin.math.*
import java.util.Scanner

val reader = Scanner(System.`in`);

fun solve(){
    var x: Int = reader.nextInt();
    var y: Int = reader.nextInt();

    var t: Int = min(x, y) - 1;

    println("$t ${x - t} ${y - t}");
}

fun main(){
    var q: Int =  reader.nextInt();

    for(i in 0 until q){
        solve();
    }
}