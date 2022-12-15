from sys import stdin, stdout

def xinput():
    return stdin.readline().rstrip()

q = int(xinput())

for _ in range(q):
    n, k = [int(x) for x in xinput().split()]
    a = [int(x) for x in xinput().split()]

    idx = []
    for i in range(n):
        if a[i] % 2 == 1:
            idx.append(i)

    if (len(idx) % 2) != (k % 2):
        stdout.write("NO\n")
        continue

    if len(idx) < k:
        stdout.write("NO\n")
        continue

    stdout.write("YES\n")
    for i in range(k - 1):
        stdout.write(str(idx[i] + 1) + " ")
    stdout.write(str(n) + "\n")