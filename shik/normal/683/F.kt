import java.util.Scanner
import java.util.Arrays

fun compact(s: String): String {
    var ns = ""
    for (i in 0..s.length - 1) {
        if (i > 0 && s[i-1] == ' ' && s[i] == ' ') continue
        ns += s[i]
    }
    return ns
}

fun fix(s: String): String {
    var ns = ""
    for (i in 0..s.length - 1) {
        if (i + 1 < s.length && s[i] == ' ' && (s[i+1] == ',' || s[i+1] == '.')) continue
        if (i > 0 && s[i] != ' ' && (s[i-1] == ',' || s[i-1] == '.')) ns += " "
        ns += s[i]
    }
    return ns
}

fun cap(s: String): String {
    var ns = ""
    var flag = true
    for (i in 0..s.length - 1) {
        if (flag && s[i].isLowerCase()) {
            ns += s[i].toUpperCase()
            flag = false
        } else {
            ns += s[i]
        }
        if (s[i] == '.') flag = true
    }
    return ns
}

fun main(args: Array<String>) {
    var s = readLine()!!
    s = s.trim()
    s = s.toLowerCase()
    s = compact(s)
    s = fix(s)
    s = cap(s)
    println(s)
}