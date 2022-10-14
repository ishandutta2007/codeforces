n = int(input())
l = 0
r = n // 2 + 2
while r - l > 1:
    m = (l + r) // 2
    vasya = 0
    petya = 0
    x = n
    while x:
        if x >= m:
            vasya += m
            x -= m
            petya += x // 10
            x -= x // 10
        else:
            vasya += x
            x = 0
    if vasya >= (n + 1) // 2:
        r = m
    else:
        l = m
print(l + 1)