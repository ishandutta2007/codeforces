n, t = map(int, input().split())
A = []
for i in range(n):
    s, d = map(int, input().split())
    if s >= t:
        A.append(s - t) 
    else:
        A.append((d - (t - s) % d) % d)
print(A.index(min(A)) + 1)