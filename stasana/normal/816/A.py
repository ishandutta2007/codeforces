def to_string(n):
    s = str(n)
    if n < 10:
        s = "0" + s
    return s

s1, s2 = map(int, input().split(":"))

res = 0
while(to_string(s1) != to_string(s2)[::-1]):
    res += 1
    s2 += 1
    if(s2 == 60):
        s2 = 0
        s1 += 1
    if(s1 == 24):
        s1 = 0
print(res)