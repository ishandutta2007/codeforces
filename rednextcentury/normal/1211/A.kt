import java.util.Arrays
fun main() {
    var n = readLine()!!.toInt()
    val a= arrayOf(readLine()!!.split(" ").map(String::toInt))
var values = a.get(0);
    var A=-1;
    var mn1 = 1000000003;
    for (i in 0..(n-1)){
        if (values[i]<mn1)mn1=values[i];
    }
    var B=-1;
    var mn2 = 1000000003;
    for (i in 0..(n-1)){
        if (values[i]<mn2 && values[i]!=mn1)mn2=values[i];
    }
    var C=-1;
    var mn = 1000000003;
    for (i in 0..(n-1)){
        if (values[i]<mn && mn1!=values[i] && mn2!=values[i])mn=values[i];
    }
    for (i in 0..(n-1)){
        if (values[i]==mn){
            C=i+1;
        } else if (values[i]==mn1)A=i+1;
        else if (values[i]==mn2)B=i+1;
    }
    if (C==-1){println(-1);println(-1);println(-1);}
    else {println(A);println(B);println(C);}
}