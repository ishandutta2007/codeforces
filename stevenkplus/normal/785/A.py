d = {
'Tetrahedron': 4,
'Cube': 6,
'Octahedron': 8,
'Dodecahedron': 12,
'Icosahedron': 20,
}
n = int(raw_input())
s = 0
for i in range(n):
  s += d[raw_input()]
print s