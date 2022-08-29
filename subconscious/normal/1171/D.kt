fun main(){
    val (a,b,c)=readLine()!!.split(" ").map{it.toInt()}
    val (x,y,z)=readLine()!!.split(" ").map{it.toInt()}
    if(x<a||x+y<a+b||x+y+z<a+b+c)println("NO")else println("YES")
}