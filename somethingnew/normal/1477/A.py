def gcd(a1, b):
    while b != 0:
        a1, b = b, a1 % b
    return a1
 
 
t = int(input())
for j in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        ans = gcd(ans, a[i] - a[(i - 1 + n) % n])
    if ans == 0:
        print("NO")
    if (k % ans == a[0] % ans):
        print("YES")
    else:
        print("NO")