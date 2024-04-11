from sys import setrecursionlimit
setrecursionlimit(10 ** 6)
def dynamic(i, fed):
    if d[i][fed] is not None:
        return d[i][fed]
    if fed:
        d[i][fed] = max(b[i] + dynamic(i + 1, True), c[i] + dynamic(i + 1, False))
    else:
        d[i][fed] = max(a[i] + dynamic(i + 1, True), b[i] + dynamic(i + 1, False))
    return d[i][fed]

n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
d = [[None, None] for i in range(n)]
d[n - 1] = [a[n - 1], b[n - 1]]
print(dynamic(0, False))