a = int(input())
ans = 1
a += 1
while '8' not in str(a):
    ans += 1
    a += 1
print(ans)