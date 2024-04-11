#http://codeforces.com/problemset/problem/248/A

n = int(input())
lsum, rsum = 0, 0 #scott
for i in range(n):
    x,y = map (int, input().split()) #scott
    lsum += x; rsum += y
print (min (lsum, n - lsum) + min (rsum, n - rsum))