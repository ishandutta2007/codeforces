function readInt() {
    return Number(readline());
}

function readInts() {
    return readline().split(" ").map(Number);
}

function cmpInt(a, b) {
    return a - b;
}

var n = readInt();
var a = readInts();
a.sort(cmpInt);
var ans = 0;
for (var i = 0; i < n; i++) {
    ans += Math.abs(i + 1 - a[i]);
}
print(ans);