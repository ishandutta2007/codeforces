import sys
input, print = sys.stdin.readline, sys.stdout.write

MAX = 2000

basis = [0] * MAX
indices = [0] * MAX

def add(x, y):
    mask = 1 << y
    for i in range(MAX):
        if x >> i & 1:
            if basis[i] == 0:
                basis[i] = x
                indices[i] = mask
                return
            x ^= basis[i]
            mask ^= indices[i]

def query(x):
    mask = 0
    for i in range(MAX):
        if x >> i & 1:
            x ^= basis[i]
            mask ^= indices[i]
    return mask if x == 0 else -1

m = int(input())
for i in range(m):
    x = int(input())
    mask = query(x)
    if mask == -1:
        print(str(0) + "\n")
    else:
        ret = [str(i) for i in range(MAX) if mask >> i & 1]
        print(str(len(ret)) + " " + " ".join(ret) + "\n")
    add(x, i)