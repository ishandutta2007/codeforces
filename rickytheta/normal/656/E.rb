n=gets.chomp.to_i

g = []
n.times{|i|
  g[i] = gets.chomp.split.map{|x| x.to_i}
}
n.times{|k|
  n.times{|i|
    n.times{|j|
      tmp = g[i][k] + g[k][j]
      g[i][j] = [g[i][j],tmp].min
    }
  }
}
mx = 0
n.times{|i|
  n.times{|j|
    mx = [mx,g[i][j]].max
  }
}
puts mx