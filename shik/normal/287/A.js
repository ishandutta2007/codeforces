"use strict";

function check(s) {
    for (var i = 0; i < 3; i++) {
        for (var j = 0; j < 3; j++) {
            var c = s[i][j];
            if (c == s[i][j+1] && c == s[i+1][j] && c == s[i+1][j+1]) return true;
        }
    }
    return false;
}

function flip(c) {
    if (c == "#") return ".";
    else return "#";
}

var s = []
for (var i = 0; i < 4; i++) s.push(readline().split(""));

var ans = false;
for (var i = 0; i < 4; i++) {
    for (var j = 0; j < 4; j++) {
        s[i][j] = flip(s[i][j]);
        if (check(s)) ans = true;
        s[i][j] = flip(s[i][j]);
    }
}
print(ans ? "YES" : "NO");