d = {"Tetrahedron": 4, "Cube": 6, "Octahedron": 8, "Dodecahedron": 12, "Icosahedron": 20}
n = int(input())
x = 0
for i in range(n):
    x += d[input()]
print(x)