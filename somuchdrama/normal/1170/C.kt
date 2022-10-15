fun main(args: Array<String>){
    val z=readLine()!!.toInt()
    repeat(z){
        var s=readLine()!!.toCharArray()
        val t=readLine()!!.toString()
        var ptr=0;
        var ok=1;
        for(c in t){
            if(ptr==s.size){
                ok=0;
                break;
            }
            if(c==s[ptr]){
                ptr++
            }else if(c=='-'&&s[ptr]=='+'){
                ok=0;
                break;
            }else if(c=='+'&&s[ptr]=='-'){
                if(ptr+1<s.size&&s[ptr+1]=='-'){
                    ptr+=2
                }else{
                    ok=0;
                    break;
                }
            }
        }
        if(ok==1&&ptr==s.size)println("YES")
        else println("NO")
    }
}