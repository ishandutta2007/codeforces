fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    for (ca in 1..t) {
        val s = readLine()!!.toString()
        if (s.all { x -> x == '=' }) {
            println('=')
        } else {
            if (s.all { x -> x != '>' }) {
                println('<')
            } else if (s.all {x -> x != '<'}) {
                println('>')
            } else {
                println('?')
            }
        }
    }
}