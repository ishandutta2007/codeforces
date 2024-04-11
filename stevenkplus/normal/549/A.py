n, m = map(int, raw_input().split())

grid = [raw_input() for i in range(n)]
squares = []

for i in range(n - 1):
  for j in range(m - 1):
    squares.append(grid[i][j:j + 2] + grid[i + 1][j: j + 2])

def is_face(square):
  return set(square) == set('face')

faces = filter(is_face, squares)
print len(faces)