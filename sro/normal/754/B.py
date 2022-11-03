g,s=[input() for i in range(4)],set()
for i in range(4):
	s.add(g[i][:3])
	s.add(g[i][1:])
	s.add(g[0][i]+g[1][i]+g[2][i])
	s.add(g[1][i]+g[2][i]+g[3][i])
for i in range(2):
	for j in range(2):
		s.add(g[i][j]+g[i+1][j+1]+g[i+2][j+2])
		s.add(g[i][j+2]+g[i+1][j+1]+g[i+2][j])
print('YES' if {'.xx','x.x','xx.'}&s else 'NO')