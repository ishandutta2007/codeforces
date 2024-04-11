n, m, k = gets.split.map {|x| Integer x}
a = Array.new(n)
for i in 0...n
  a[i] = Array.new
  s = gets.split.map {|x| (Integer x) - 1}
  for j in 0...m
    a[i][j] = s[j]
  end
end
bad_cell = [false] * k
bad_core = [false] * n
prev = [nil] * k
time = [0] * n
for t in 0...m
  used = [false] * k
  for c in 0...n
    if bad_core[c] or a[c][t] == -1
      next
    end
    if bad_cell[a[c][t]] or used[a[c][t]]
      bad_cell[a[c][t]] = true
      bad_core[c] = true
      if time[c] == 0
        time[c] = t + 1
      end
      bad_core[prev[a[c][t]]] = true
      if time[prev[a[c][t]]] == 0
        time[prev[a[c][t]]] = t + 1
      end
    end
    used[a[c][t]] = true
    prev[a[c][t]] = c
  end
end
puts time