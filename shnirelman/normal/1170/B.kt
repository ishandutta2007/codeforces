fun main(args : Array<String>) {
    var n : Int = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map({it.toInt()})
    
    var mx1 = 0
    var mx2 = 0
    
    var ans : Int = 0
    
    for(a1 in a) {
        //print("$a1 $mx1 $mx2\n")
        if(mx2 > a1)
            ans++
            
        if(a1 > mx1) {
            mx2 = mx1
            mx1 = a1
        } else if(a1 > mx2) {
            mx2 = a1
        }
    }
    
    print("$ans")
}