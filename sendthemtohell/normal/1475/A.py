t = int(input())
for _ in range(t):
    x = int(input())
    print( "YES" if (x&(x-1)) else "NO")