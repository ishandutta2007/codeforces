from sys import stdin, stdout
def solve():
    n = int(stdin.readline())
    pole = [[0 for i in range(n)] for i in range(n)]
    num = 1
    for i in range(1, 2 * n):
        n2 = True
        for j in range(n):
            if i - j < n:
                pole[i-j][j] = num * n2
            n2 = not n2
        num *= 2
    for i in range(n):
        stdout.write(' '.join(list(map(str, pole[i]))) + '\n')
        stdout.flush()
    q = int(stdin.readline())
    for i in range(q):
        ans = []
        pos = [n-1,n-1]
        z = int(stdin.readline())
        k = pow(2, 2 * n - 4)
        z %= k * 2
        while pos != [0,0]:
            ans.append([pos[0] + 1, pos[1] + 1])
            if pos[0] == 0:
                pos[1] -= 1
                continue
            if pos[1] == 0:
                pos[0] -= 1
                continue
            nm = z // k
            if bool(nm) ^ bool(pole[pos[0] - 1][pos[1]]):
                pos[1] -= 1
            else:
                pos[0] -= 1
            z %= k
            k //= 2
        ans.append([1, 1])
        ans.reverse()
        for i in ans:
            stdout.write(str(i[0]) + ' ' + str(i[1]) + '\n')
            stdout.flush()
solve()