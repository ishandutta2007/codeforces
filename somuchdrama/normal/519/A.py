A = [''] * 8
b = 0
w = 0
def count(v):
    global w, b
    if v == 'Q':
        w += 9
    elif v == 'R':
        w += 5
    elif v == 'B':
        w += 3
    elif v == 'N':
        w += 3
    elif v == 'P':
        w += 1
    elif v == 'q':
        b += 9
    elif v == 'r':
        b += 5
    elif v == 'b':
        b += 3
    elif v == 'n':
        b += 3
    elif v == 'p':
        b += 1
for i in range(8):
    A[i] = input()
    for j in range(8):
        count(A[i][j])
if b > w:
    print("Black")
elif b == w:
    print("Draw")
else:
    print("White")