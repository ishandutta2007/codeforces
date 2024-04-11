import java.io.*
import java.util.*
fun main(args: Array<String>) = bufferOut { readSolveWrite() }
private fun PrintWriter.readSolveWrite() {
    val sc = Scanner(System.`in`)
    val m=sc.nextInt()
    val a=IntArray(m)
    for(i in 0..m-1){
        a.set(i,sc.nextInt())
    }
    var n=0;
    for (i in a)if(i==-1)n++;
    println(n)
    var nx=IntArray(n)
    var bc=IntArray(n)
    for (i in 0..n-1){
        nx[i]=(i+1)%n
        bc[i]=(i-1+n)%n
    }
    var sz=IntArray(n)
    var st=IntArray(n)
    var ss=IntArray(n)
    var ans=IntArray(m-n)
    var ptr=0;
    var lt=0;
    for(i in a){
        if(i==-1){
            lt++
            if(lt!=n){
                val gof=nx[ptr]
                val gob=bc[ptr]
                nx[gob]=gof
                bc[gof]=gob
            }
        }else{
            sz[ptr]++
        }
        ptr=nx[ptr]
        if(ptr==n)ptr=0
    }
    for (i in 0..n-1){
        nx[i]=(i+1)%n
        bc[i]=(i-1+n)%n
    }
    ptr=0
    ss[0]=0
    st[0]=0
    for(i in 1..n-1){
        st[i]=st[i-1]+sz[i-1]
        ss[i]=st[i-1]+sz[i-1]
    }
    for(i in a){
        if(i==-1){
            lt++
            if(lt!=n){
                val gof=nx[ptr]
                val gob=bc[ptr]
                nx[gob]=gof
                bc[gof]=gob
            }
        }else{
            ans[st[ptr]]=i
            st[ptr]++
        }
        ptr=nx[ptr]
    }
    for(i in 0..n-1){
        print(sz[i])
        print(' ')
        println(ans.slice(ss[i]..st[i]-1).joinToString(" "))
    }
}
private fun bufferOut(block: PrintWriter.() -> Unit) = PrintWriter(System.out).use { block(it) }