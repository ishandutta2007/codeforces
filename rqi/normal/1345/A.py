

t = int(input())

for T in range(t):
    n, m = map(int, input().split(" "))
    if max(n, m) == 2 or min(n, m) == 1:
        print("YES")
    else:
        print("NO")