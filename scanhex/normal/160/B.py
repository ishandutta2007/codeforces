__autor__ = 'Alex'
input()
n = [int(i) for i in input().rstrip()]
n1, n2 = n[:len(n) // 2], n[len(n) // 2:]
n1.sort()
n2.sort()
print('YES' if all(map(lambda x: n1[x] < n2[x], range(len(n) // 2))) or all(map(lambda x: n1[x] > n2[x], range(len(n) // 2))) else 'NO')