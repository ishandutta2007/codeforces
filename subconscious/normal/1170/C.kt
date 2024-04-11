class seg(val l:Int,val r:Int,val key:Int)
fun gcd(x:Int,y:Int):Int{return if(y==0)x else gcd(y,x%y)}
fun raw()=readLine()!!
fun innum()=raw().toInt()
fun inlin()=(raw().split(" ").map{it.toInt()}).toIntArray()
fun main(){
    var t=innum()
    repeat(t){
        var s=raw()
        s=s+'#'
        var t=raw()
        t=t+'#'
        var x=0
        var y=0
        while(s[x]!='#'||t[y]!='#'){
            if(s[x]==t[y]){
                ++x
                ++y
            }else if(s[x]=='-'&&s[x+1]=='-'&&t[y]=='+'){
                x+=2
                ++y
            }else break
        }
        if(s[x]=='#'&&t[y]=='#')println("YES")
        else println("NO")
    }
}