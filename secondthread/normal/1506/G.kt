
//returns a bitmask
fun getUsed(s: String, takeFirst: Char): Int {
    var res=0;
    var seen=false;
    s.forEach {
        if (it==takeFirst)
            seen=true;
        if (seen)
            res= res or (1 shl (it-'a'));
    }
    return res;
}

fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        var s=readLine()!!;
        var ans="";
        var allChars = getUsed(s, s[0]);
        var takeNow='z';
        while (takeNow>='a') {
            if (getUsed(s, takeNow)==allChars) {
                ans+=takeNow;
                val firstIndex=s.indexOfFirst { it==takeNow };
                if (firstIndex==-1) {
                    takeNow--;
                    continue
                };
                s=s.substring(firstIndex);
                s=s.replace(takeNow.toString(), "");
                if (s.isEmpty()) {
                    break;
                }
                allChars-=1 shl (takeNow-'a');
                takeNow='z'+1;
            }
            takeNow--;
        }
        println(ans);
    }
}