fun main() {
    var t = readLine()!!.toInt()
    for (q in 1..t){
      var (x1, y1) = readLine()!!.split(' ')
      var x = x1.toInt()
      var y = y1.toInt()
      var a = x1.toInt()
      var b = y1.toInt()
      if (y < x){
        x = b
        y = a
      }
      var res = IntArray(3)
      res[0] = 1
      res[1] = x - 1
      res[2] = y -  x + 1
      println(res.joinToString(" "))
    }
}