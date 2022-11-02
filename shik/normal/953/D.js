var C = [
  [3, 3, 0, 4, 4, 0, 3, 3],
  [3, 3, 0, 4, 4, 0, 3, 3],
  [2, 2, 0, 3, 3, 0, 2, 2],
  [2, 2, 0, 3, 3, 0, 2, 2],
  [1, 1, 0, 2, 2, 0, 1, 1],
  [1, 1, 0, 2, 2, 0, 1, 1]
];
var n = 6;
var m = 8;
var a = [];
for (var i = 0; i < n; i++) {
  a.push(readline().split(''));
}

var x = -1, y = -1, mx = -1;

for (var i = 0; i < n; i++) {
  for (var j = 0; j < m; j++) {
    if (a[i][j] != '.') continue;
    var c = C[i][j];
    if (c > mx) {
      mx = c;
      x = i;
      y = j;
    }
  }
}

a[x][y] = 'P';
for (var i = 0; i < n; i++) {
  print(a[i].join(''));
}