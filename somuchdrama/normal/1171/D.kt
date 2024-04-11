fun main(args: Array<String>) {
    var (x,y,z)=readLine()!!.split(" ").map{it.toInt()}
    var (a,b,c)=readLine()!!.split(" ").map{it.toInt()}
    if(a<x)println("NO")
    else{
        a-=x
        if(a+b<y)println("NO")
        else{
            if(a+b-y+c<z)println("NO")
            else println("YES")
        }
    }
}