t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    x, y = map(int, input().split())
    if((a == x and a == b + y) or (a == y and a == b + x) or (b == x and b == a + y) or (b == y and b == a + x)):
        print("YES")
    else:
        print("NO")