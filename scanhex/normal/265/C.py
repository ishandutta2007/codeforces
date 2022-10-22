__autor__ = 'Alex239'
s = input().rstrip()
print("\n".join([str(i + 1) for i in range(len(s)) if s[i] == 'r']), "\n".join([str(i + 1) for i in range(len(s) - 1, -1, -1) if s[i] == 'l']), sep="\n")