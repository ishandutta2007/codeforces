n = int(input()) + 1
s = sum(map (int, input().split()))

ans = 5
for i in range (1, 6):
    if (s + i) % n == 1: ans -= 1
print(ans)