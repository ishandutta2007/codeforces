n = int(input()) 
A = list(map(int, input().split())) 
B = [4, 8, 15, 16, 23, 42]
p1, p2, p3, p4, p5, p6 = 0,0,0,0,0,0
for i in A:
    if i == 4:
        p1 += 1
    elif i == 8:
        if p1:
            p1 -= 1
            p2 += 1
    elif i == 15:
        if p2:
            p2 -= 1
            p3 += 1
    elif i == 16:
        if p3:
            p3 -= 1
            p4 += 1
    elif i == 23:
        if p4:
            p4 -= 1
            p5 += 1
    elif i == 42:
        if p5:
            p5 -= 1
            p6 += 1
print(n-6*p6)