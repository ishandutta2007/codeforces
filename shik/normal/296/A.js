function readInt() {
  return Number(readline());
}

function readInts() {
  return readline().split(" ").map(Number);
}

var n = readInt();
var a = readInts();
var cnt = {};
a.forEach(function(x) {
  cnt[x] = (cnt[x] || 0) + 1;
});
var mx = 0;
for (var k in cnt) {
  mx = Math.max(mx, cnt[k]);
}
if (mx > Math.ceil(n / 2)) print("NO");
else print("YES");