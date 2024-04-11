
def solve():
    x ,y ,k = map(int ,input().split())
    r = y * k - 1 + k
    print(k + (r + x - 2) // (x - 1))
for i in range(int(input())):
    solve()