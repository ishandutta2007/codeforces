n = int(input())
print("+------------------------+")

A = [[0 for i in range(11)] for i in range(3)]

def printing():
    global A, s4
    s2 = '|'
    for i in range(11):
        if A[0][i] == 0:
            s2 += "#."
        else:
            s2 += "O."
    s2 += "|D|)"
    print(s2)

    s3 = '|'
    for i in range(11):
        if A[1][i] == 0:
            s3 += "#."
        else:
            s3 += "O."
    s3 += "|.|"
    print(s3)
    print(s4)

    s5 = '|'
    for i in range(11):
        if A[2][i] == 0:
            s5 += "#."
        else:
            s5 += "O."
    s5 += "|.|)"
    print(s5)

    
        

if n > 2:
    s4 = "|O.......................|"
    n -= 1
else:
    s4 = "|#.......................|"
for i in range(n):
    A[(i) % 3][i // 3] = 1
##print(A)
printing()
print("+------------------------+")