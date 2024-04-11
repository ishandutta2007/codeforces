c, v0, v1, a, l = map(int, input().split())

t = v0
cv = v0
d = 1
while t < c:
    cv += a
    if cv > v1:
        cv = v1
    t += cv - l
    d += 1

print(d)