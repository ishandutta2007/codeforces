def mult(m1, m2):
    p = len(m1)
    q = len(m2)
    r = len(m2[0])
    m3 = [[0] * r for _ in range(p)]
    for x in range(p):
        for y in range(r):
            for z in range(q):
                m3[x][y] += m1[x][z] * m2[z][y]
                m3[x][y] %= (M-1)
    return m3


def binpow(mat, x):
    if x == 0:
        return E
    elif x % 2:
        return mult(mat, binpow(mult(mat, mat), x // 2))
    else:
        return binpow(mult(mat, mat), x // 2)


matrix = [[0, 1, 0], [0, 0, 1], [1, 1, 1]]
E = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
M = 10 ** 9 + 7
n, f1, f2, f3, c = map(int, input().split())
matrix = binpow(matrix, n-1)
g1 = matrix[0][0]
g2 = matrix[0][1]
g3 = matrix[0][2]
ans = pow(c * f1, g1, M) * pow(c * c * f2, g2, M) % M * pow(c * c * c * f3, g3, M) % M * pow(c, (10 ** 9 * (M - 1) - n) % (M - 1), M) % M
print(ans % M)