n, x, y = map(int, input().split())
l = list(map(int, input().split()))
for i in range(n):
    m1 = min(l[j] for j in range(max(0, i - x), i)) if (i > 0 and x > 0) else 1000000001
    m2 = min(l[j] for j in range(i + 1, min(i + y + 1, n))) if (i < n - 1 and y > 0) else 1000000001
    if(l[i] < min(m1, m2)):
        print(i + 1)
        exit()