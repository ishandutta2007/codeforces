from sys import stdout
def solve():
    n = int(input())
    lst = [i for i in range(1, n + 1)]
    ans = []
    num = lst[-1]
    lst.pop()
    while lst[-1] != 2:
        if (num + lst[-1] - 1) // lst[-1] > lst[-1]:
            num = (num + lst[-1] - 1) // lst[-1]
            ans.append([n, len(lst)])
        ans.append([len(lst), n])
        lst.pop()
    while num != 1:
        num = (num + 1) // 2
        ans.append([n, 2])
    stdout.write(str(len(ans)) + '\n')
    for a, b in ans:
        stdout.write(str(a) + ' ' + str(b) + '\n')

for i in range(int(input())):
    solve()