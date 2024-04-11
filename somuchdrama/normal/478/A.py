q, w, e, r, t = map(int, input().split())
if (q+w+e+r+t )%5==0 and (q+w+e+r+t) != 0:
    print((q+w+e+r+t )//5)
else:
    print(-1)